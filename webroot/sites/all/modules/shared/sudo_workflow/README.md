# Contents of this File

* [About Sudo Workflow](#about-sudo-workflow)
* [Dependencies](#dependencies)
* [Configuration and features](#configuration-and-features)
* [Roadmap](#roadmap)

# About Sudo Workflow

Sudo Workflow provides some extra functions for developers to use to get Workflow
to do what they want.

Workflow is nice, but it can sometimes get in the way the developers way. For
instance, if you want to create content in a given state, like when you are
importing content or creating content for tests. Workflow forces you to transition
the content through each intermediate state and the easiest way to do that is as
user 1. Sudo Workflow provides functions to make that easier for developers.

# Dependencies

* [Workflow](https://www.drupal.org/project/workflow)

# Configuration and features

If you want to change the user that will perform the transitions, you can set it
using the `sudo_workflow_admin_uid` variable. User 1 will be used by default.

**NOTE:** This user must have permission to transition the entity to all states.

The primary function is:

```
sudo_workflow_transition_to_state($entity_type, $entity, $field_name, $target_sid, $comment);
```

- The `$field_name` is the field name when using the Workflow Field module. If
  using the Workflow Node module, pass an empty string.
- The comment is optional.

# Roadmap

TBD
