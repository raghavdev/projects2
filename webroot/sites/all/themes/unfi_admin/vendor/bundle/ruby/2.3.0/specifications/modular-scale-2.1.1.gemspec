# -*- encoding: utf-8 -*-
# stub: modular-scale 2.1.1 ruby lib

Gem::Specification.new do |s|
  s.name = "modular-scale"
  s.version = "2.1.1"

  s.required_rubygems_version = Gem::Requirement.new(">= 1.3.6") if s.respond_to? :required_rubygems_version=
  s.require_paths = ["lib"]
  s.authors = ["Scott Kellum", "Mason Wendell", "Adam Stacoviak"]
  s.date = "2013-12-20"
  s.description = "A modular scale is a list of values that share the same relationship. These\nvalues are often used to size type and create a sense of harmony in a design. Proportions within\nmodular scales are all around us from the spacing of the joints on our fingers to branches on\ntrees. These natural proportions have been used since the time of the ancient Greeks in\narchitecture and design and can be a tremendously helpful tool to leverage for web designers."
  s.email = ["scott@scottkellum.com", "mason@thecodingdesigner.com", "adam@stacoviak.com"]
  s.extra_rdoc_files = ["changelog.md", "license.md", "readme.md"]
  s.files = ["changelog.md", "license.md", "readme.md"]
  s.homepage = "http://modularscale.com"
  s.licenses = ["MIT"]
  s.rubygems_version = "2.5.1"
  s.summary = "Modular scale calculator built into your Sass."

  s.installed_by_version = "2.5.1" if s.respond_to? :installed_by_version

  if s.respond_to? :specification_version then
    s.specification_version = 4

    if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
      s.add_runtime_dependency(%q<compass>, [">= 0.12.0"])
    else
      s.add_dependency(%q<compass>, [">= 0.12.0"])
    end
  else
    s.add_dependency(%q<compass>, [">= 0.12.0"])
  end
end
