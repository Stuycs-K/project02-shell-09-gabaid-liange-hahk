[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/Tfg6waJb)
# Systems Project2 - MyShell

Members: Daniel Gabai, Edmund Liang, Keith Hah

Creative Team Name: Can't segfault if you can't read

Features implemented:

- User input
- Parsing the user input line to separate the command from its arguments
- Forking for each command and having the child execvp that command
- Waiting until the exec'd program exits before going back to user input
- Semicolons to separate commands
- Prompt includes the cwd path
- Quitting the shell with exit or Ctrl+D
