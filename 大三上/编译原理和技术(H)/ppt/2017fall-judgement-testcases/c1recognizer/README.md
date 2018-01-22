# C1 Language Recognizer (Reference Version)

A C1 language recognizer library built on ANTLR v4, which constructs an abstract syntax tree on given source input.

## Build Requirement

* CMake 3.5 or later
* Any GCC compatible C++ compiler, C++ 11 must be supported
* Any java runtime environment (JRE), preferring version for Java 8
* pkg-config
* uuid-dev

If you have the patience to configure those correctly on Windows, using Windows as the expirement platform is okay.
Otherwise please choose one of the easy-to-use Linux distributions. (Note: Windows Subsystem for Linux will work fine)

For example, installing those in Ubuntu with `apt`:

```bash
sudo apt install cmake g++ openjdk-8-jre-headless pkg-config uuid-dev
```

Also, it would take a while to build it for the first time. This is because it needs to build the dependency antlr4cpp.
And parallel building won't work on it; it seems that CMake is the one to be blamed.

Besides these, you're also expected to download an ANTLR complete jar file. This is expected throughout this project.
You may find it from [ANTLR v4 Official Site](http://www.antlr.org/).

## Building

For first time building:
```bash
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Debug -DANTLR4CPP_JAR_LOCATION=/path/to/your/antlr.jar ..
make
cmake ..
make -j
```

After that, each time you have any modification, simply do
```bash
make -j
```

To avoid UI unresponding, you may want to replace `-j` option with `-jN`, where `N` is parallel task number you expecting.

## ANTLRv4 Usage

For the building work, I've setup the whole CMake project that will work easily as described above.

And for the most special, magic and wonderful part of ANTLR, visualization, follow these:

* Rail-road or ADT graphs: Using Visual Studio Code will be the best choice. Have ANTLR plugin installed, you'll gonna
  find those options when you right-click on the editor.
* Testing grammars (including parse tree visualization):
  > If you'd like to see GUI rather than console-printed parse tree, you'll need to first install JDK on your host
  > system (Windows or Linux, DO NOT use WSL here if you don't have sufficient knowledge on configuring X11
  > environment, which is needed for the GUI to show up). However if you don't want the GUI version visualized parse
  > tree, just ignore this tip.
  
  First of all, you need to ensure `.` and ANTLR v4 JAR file exists in your CLASSPATH.
  * In PowerShell, it is `$env:CLASSPATH`.
  * In Linux-like shells, it is `$CLASSPATH`.

  Then, use ANTLR to generate `.java` source files from grammar files.
  ```sh
  java org.antlr.v4.Tool *.g4
  ```

  After that, compile generated sources.
  ```sh
  javac *.java
  ```

  Then, use the `grun` tool comes with antlr to test your grammars.
  ```sh
  # Testing lexer
  java org.antlr.v4.gui.TestRig C1Lexer tokens -tokens ../../test/test_cases/simple.c1
  # Testing lexer + parser, GUI version parse tree
  java org.antlr.v4.gui.TestRig C1 compilationUnit -gui ../../test/test_cases/simple.c1
  # Testing lexer + parser, console printed version parse tree
  java org.antlr.v4.gui.TestRig C1 compilationUnit -tree ../../test/test_cases/simple.c1
  ```
