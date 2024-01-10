# TDT4102 - Prosedyre- og objektorientert programmering Homework Repo

## Overview
This repository contains my homework submissions for the course TDT4102 - Prosedyre- og objektorientert programmering for the 2024 spring on NTNU trondheim. It primarily focuses on assignments and projects involving procedural and object-oriented programming in C++.

Including instructions for running your C++ code using the debugger in Visual Studio Code (VSCode) is a great idea, especially since it seems to be the standard practice in your course. I'll provide a modified version of the `README.md` with additional steps for running the code using VSCode's debugger:

---
## Compilation Instructions

### Prerequisites
Ensure you have the following tools installed:
- Meson (version 1.3.0 or later)
- Ninja (version 1.11.1 or later)
- A C++ compiler (e.g., Clang 17.0.5)
- SDL2 and SDL2_image libraries

### Setting Up the Environment
1. Clone the repository to your local machine.
2. Navigate to the project's root directory.

   ```bash
   cd path/to/standard_env
   ```

### Moving Files to the Standard Environment
1. **Identify the Files**: Determine which files you need to run or debug. These typically include your main C++ source files and any additional headers or resources they depend on.

2. **Copy Files to the Standard Environment**: Manually copy these files into the appropriate directory within the standard environment. This ensures that all necessary dependencies and configurations are in place for compiling and running the code.

   For example, if your standard environment directory is `E:/standard_env/`, and your source file is `oppgave_1.cpp`, copy `oppgave_1.cpp` into `E:/standard_env/`.


### Compiling the Project
This project uses Meson for its build system. To compile the project, follow these steps:

1. **Create the Build Directory**: 
   Run the following command to create a build directory and set up the environment. This command also configures the build type as `debug`.

   ```bash
   meson setup builddir --buildtype debug
   ```

2. **Build the Project**: 
   Once the environment is set up, you can compile the project using Ninja:

   ```bash
   ninja -C builddir
   ```

   This will compile the project and generate the executable in the `builddir` directory.

3. **Running the Executable**: 
   After successful compilation, run the executable from the build directory:

   ```bash
   ./builddir/your_executable_name
   ```

   Replace `your_executable_name` with the name of your project's executable.


## Running the Code Using VSCode Debugger

### Debugging the Project
1. After building the project, go to the 'Run and Debug' view in VSCode (usually accessible via the sidebar or the `Ctrl+Shift+D` shortcut).
2. Select the appropriate debug configuration from the dropdown at the top. This configuration should be set up to run the executable generated by your build.
3. Click the 'Start Debugging' button (green arrow) or press `F5` to start the debugging session.
4. VSCode will launch the program and attach the debugger. You can now set breakpoints, step through the code, inspect variables, etc.

### Troubleshooting
- If the debugger does not start or cannot find the executable, ensure that the debug configurations in `.vscode/launch.json` are set up correctly, pointing to the built executable.
- For issues related to compiler warnings or errors (as seen in the terminal output), address the specific issues in your code or environment setup as required.

## Initial environment Setup Instructions

The initial setup instructions for the development environment are detailed in the "Øving 1" PDF document provided with the course materials. Please refer to this document for the standard setup procedure.

### Important Note on Modifications

Please be aware that I have made modifications to the standard environment to better suit my development workflow. While these changes are beneficial for my current setup, there is a possibility that they might not align perfectly with future requirements or updates to the course environment.

If you encounter any issues or inconsistencies with the modified environment, I recommend consulting the `Øving0.pdf` for the original setup guidelines. 
