module.exports = function(grunt) {

  // Project configuration.
  grunt.initConfig({
    project_theme: 'unfi_admin',
    theme_base: 'drupal/sites/all/themes/<%= project_theme %>',

    pkg: grunt.file.readJSON('package.json'),
    jshint: {
      options: {
        force: true,
      },
      check: {
        src: ['<%= watch.scripts.files %>'],
      },
    },
    compass: {
      dist: {
        options: {
          config: '<%= theme_base %>/config.rb',
          basePath: '<%= theme_base %>',
        }
      }
    },
    watch: {
      scripts: {
        files: [
          '<%= theme_base %>/js/*.js',
          '!<%= theme_base %>/js/*.min.js'
        ],
        tasks: ['jshint'],
      },
      sass: {
        files: [
          '<%= theme_base %>/sass/*.scss',
        ],
        tasks: ['compass'],
      },
    },
  });
  grunt.loadNpmTasks('grunt-contrib-jshint');
  grunt.loadNpmTasks('grunt-contrib-watch');
  grunt.loadNpmTasks('grunt-contrib-compass');

  grunt.registerTask('default', ['jshint', 'compass'])

};
