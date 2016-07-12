 # The project name. (one word: no spaces, dashes, or underscores)
set :application, "bluemarbledm"

# List the Drupal multi-site folders.  Use "default" if no multi-sites are installed.
# set :domains, ["example.metaltoad.com", "example2.metaltoad.com"]
set :domains, ["default"]
set :tables, "common"

# Set the Diffux app id http://metaltoad:toadpower@diffux.metaltoad.com
set :diffux_app_id, -1

# Set the repository type and location to deploy from.
set :scm, :git
set :repository,  "git@github.com:metaltoad/#{application}.git"
# set :scm, :subversion
# set :repository,  "https://svn.metaltoad.com/svn/#{application}/trunk/"
# set(:scm_password) { Capistrano::CLI.password_prompt("SCM Password: ") }

# E-mail address to notify of production deployments
set :notify_email, "pm@metaltoad.com,devops@metaltoad.com"

# Set the database passwords that we'll use for maintenance. Probably only used
# during setup.
set(:db_root_pass) { '-p' + Capistrano::CLI.password_prompt("Production Root MySQL password: ") }
set(:db_pass) { random_password }

# The subdirectory within the repo containing the DocumentRoot.
set :app_root, "drupal"

# Use a remote cache to speed things up
set :deploy_via, :remote_cache
ssh_options[:user] = 'deploy'
ssh_options[:forward_agent] = true

# Multistage support - see config/deploy/[STAGE].rb for specific configs
set :default_stage, "dev"
set :stages, %w(dev staging qa prod unfidev)

before 'multistage:ensure' do
  # Set the branch to the current stage, unless it's been overridden
  if !exists?(:branch)
    set :branch, stage
  end

  # Extra reminders for production.
  if (stage == :prod)
    before "deploy", "deploy:quality"
    after "deploy", "deploy:notify"
  end

  # Tag staging and production releases
  if (stage == :staging || stage == :prod)
    after "deploy", "deploy:tag_release"
  end
end

# Generally don't need sudo for this deploy setup
set :use_sudo, false

# This allows the sudo command to work if you do need it
default_run_options[:pty] = true

# Override these in your stage files if your web server group is something other than apache
set :httpd_group, 'apache'

# Code to add Compass to deploy process so we can remove compiled css from git repo
# build Compass artifacts
set :theme_path, "#{app_root}/sites/all/themes"
set :theme_name, "unfi_admin"

after "deploy:update_code" do

  require 'fileutils'
  tmp_theme = "/tmp/#{application}-#{release_name}"
  Dir.mkdir(tmp_theme)
  download("#{release_path}/#{theme_path}/#{theme_name}", tmp_theme, {:once => true, :recursive => true, :via => :scp})

  run_locally("cd #{tmp_theme}/#{theme_name}; bundle install --deployment ; bundle exec compass clean")
  run_locally("cd #{tmp_theme}/#{theme_name}; bundle exec compass compile --output-style compressed")
  upload("#{tmp_theme}/#{theme_name}/styles",
    "#{release_path}/#{theme_path}/#{theme_name}/styles",
     {:via => :sftp, :mkdir => true})
  # Glob is nasty, but the generated_images directory
  # option isn't supported until Compass 0.12.
  Dir.glob("#{tmp_theme}/#{theme_name}/images/*-s[0-9a-f][0-9a-f][0-9a-f][0-9a-f][0-9a-f][0-9a-f][0-9a-f][0-9a-f][0-9a-f][0-9a-f].png").each do|f|
    upload(f, "#{release_path}/#{theme_path}/#{theme_name}/images/#{File.basename(f)}")
  end

  FileUtils.rmtree(tmp_theme);
end

namespace :deploy do
  desc "Optionally run a Diffux report"
  task :diffuxreport do
    if (diffux_app_id == -1)
      puts "\n\n\033[41;30m  *** You must first create the diffux project at ***  \033[0m\n"
      puts "\033[41;30m  * http://metaltoad:toadpower@diffux.metaltoad.com *  \033[0m\n"
      puts "\033[41;30m  ***** before you are able to generate a report ****  \033[0m\n"
    else
      puts "\n\n\033[41;30m  ************************ DIFFUX REPORT? ************************  \033[0m\n"
      if Capistrano::CLI.ui.ask("Would you like a Diffux report? y/n") == 'y'
        set :username, run_locally('whoami').strip
        set :diffux_email, Capistrano::CLI.ui.ask("What email would you like it sent to?")
        set :diffux_url, "curl  --header \"Accept: application/json\" --header \"Content-Type: application/json\" --data '{\"title\": \"#{application}.#{stage} Diffux report\", \"description\": \"#{application} Diffux report initiated by #{username}\",\"delay_seconds\": 20,\"email\": \"#{diffux_email}\"}' http://metaltoad:toadpower@diffux.metaltoad.com/en/projects/#{diffux_app_id}/sweeps/trigger"
        set :diffux_result,  run_locally(diffux_url)
        puts "#{diffux_result}"
        puts "\n\n\033[41;30m  ******************** DIFFUX REPORT INITIATED ********************  \033[0m\n"
      end
    end
  end
end

after "deploy:cacheclear", "deploy:diffuxreport"
