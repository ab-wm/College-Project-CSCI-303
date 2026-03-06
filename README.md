# This is my code repository for CSCI 303

Contents:
1. [a0](a0): this is my solution for assignment #0
2. [a1](a1): this is my solution for assignment #1
3. [a2](a2): this is my solution for assignment #2
4. [a3](a3): this is my solution for assignment #3
5. [a4](a4): this is my solution for assignment #4
6. [a5](a5): this is my solution for assignment #5

Each of these directories may contain one or more C++ projects. Each project can be opened with CLion or your favorite IDE.

In this class, a C++ project is a directory with C++ code files and subdirectories that can be compiled via CMake. Each project is a C++ program that performs one or more tasks.

CMake is a tool that facilitates C++ compilation on multiple operating systems using different C++ toolchains. A C++ toolchain is set of programming tools that work together for compiling, linking, and debugging C++ programs (e.g., the GNU toolchain or the Visual Studio toolchain). 

# How can I run a C++ project?

First of all, you need to clone this repository on your machine (by running `git clone [url_of_this_repository]` on the terminal) -- git should be installed on your machine.
Cloning your repository is typically done once and this will create a working copy on your local machine, which you can synchronize with GitHub at any moment (e.g., push your code modifications to GitHub).

If you have cloned the repo and need to update your local copy of the repo, you can open the terminal, go to the directory of the repo, and run `git pull`.

A C++ project can be run through the command line (terminal) or through the CLion IDE, once g++, cmake, and CLion are installed on your machine.

## Running a project through the command line

Each project should contain two scripts:
* `build-run-unix.sh`: this one is for compiling/running the program on Linux or MacOS
* `build-run-win-msys2.sh`: this one is for compiling/running the program on Windows (through the "MSYS2 MinGW 64-bit" terminal, not the Windows terminal)

On **Linux and MacOS**, open a terminal, go the directory of the project you want to run (e.g., `cd /home/[path_to_repo]/cmake_base_project`), and run the script: `./build-run-unix.sh`. 
You may need to add execution permissions to the script by running `chmod +x ./build-run-unix.sh`

On **Windows**, open the **MSYS2 MinGW 64-bit** terminal (not the Windows terminal), go the directory of the project you want to run (e.g., `cd /c/Users/[path_to_repo]/cmake_base_project`), and run the script: `./build-run-win-msys2.sh`. 

Once the script is executed, you should see the output of the program on the terminal.

*Note*: sometimes, when you experience weird compilation errors, you may need to compile the project from scratch. In that case, before running the scrips above, you need to delete the `build-unix` or `build-win-msys2` directories (e.g., `rm -r build-win-msys2`)

## Running a project through CLion

Configuration: once you install CLion on your Machine, it will guide you through configuring the C++ Toolchain.
On Windows, CLion will guide you to configure the MinGW C++ Toolchain. It should work smoothly -- for any problem, check [this page](https://www.jetbrains.com/help/clion/quick-tutorial-on-configuring-clion-on-windows.html#MinGW), which shows how to configure it step by step.

Follow the next steps after you have configured CLion correctly (*Note*: Mac users may see different menu options to those mentioned below).

Open CLion, click on `File --> Open...` (on the menu bar), select the directory of the project you want to run, and click `OK`.

Once the project is loaded (it should take a few seconds), click on `Build --> Build project` (on the menu bar), wait until it finishes compiling and creating the executable, and then click on `Run --> Run '[name_of_the_executable]'` (or just click the green triangle icon on the menu bar)

Once these steps are completed, you should see the output of the program on the "Run" panel of CLion.

*Note*: if there is any problem building the project, you may want to try reloading the project. You can do so by clicking `File --> Reload CMake project` (on the menu bar)

# How do I create a new C++ project and submit it to GitHub?

Let's assume that you want to create a new C++ project on CLion for assignment #1, write the required code to solve the assignment, and then submit it to GitHub, so that the instructor/TA can grade your submission.

For creating a new project, we recommend that you reuse the [base project](https://github.com/CSCI-303-02-Algorithms/oscarch/tree/master/cmake_base_project) from the instructor's repository (also found in the root directory of your repository). Once you clone the instructor's repo, copy/paste the `cmake_base_project` directory into the `a1` directory.

In your local repo (inside `a1`), rename the `cmake_base_project` directory as you want or as required by the assignment, and rename the references to `cmake_base_project` in the `CMakeList.txt` and `*.sh` files. In `CMakeList.txt`, change the project name and executable. In the `*.sh`, change the executable name and (optionally) add any arguments for the program.

Add or modify any code files or directories in order to complete the assignment.

At any time during coding or after completing the assignment, you can do this to submit your code:
1. Let git know what you want to submit (i.e., add changes to git). If you want to submit all the code (files and directories) your wrote, you can run `git add *` on the terminal. If you want to submit only some directories or files, you can run `git add [path_to_directory]` or `git add [path_to_file]`
2. Commit your code changes/files to your local repository. Run the command `git commit -m "[message describing what you did]"`.
3. Push the local commits to GitHub, by running `git push`

At this point, you should have submitted your code and you should be able to see your commits (code changes) on the browser, by navigating to your repository on github.com


