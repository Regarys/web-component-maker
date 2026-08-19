# WebComponent Maker

A simple command-line project generator written in C that creates a basic web component structure from embedded HTML, CSS, and JavaScript templates.

The project is designed to generate a ready-to-use web project with a single command. The templates are converted into C header files during development and embedded directly into the compiled executable, so the final `maker` binary does not need the original template files at runtime.

### Features

<ul>
    <li>Generate a basic HTML, CSS, and JavaScript project structure</li>
    <li>Create a new project directory from a command-line argument</li>
    <li>Generate <code>index.html</code>, <code>style.css</code>, and <code>script.js</code> automatically</li>
    <li>Embed project templates directly into the compiled C executable</li>
    <li>Use <code>xxd</code> to convert template files into C header files</li>
    <li>Lightweight and dependency-free at runtime</li>
    <li>Built specifically for Linux environments</li>
</ul>

### Tech Stack

<ul>
    <li>C</li>
    <li>Linux</li>
    <li>GCC</li>
    <li><code>xxd</code></li>
    <li>HTML</li>
    <li>CSS</li>
    <li>JavaScript</li>
</ul>

### How It Works

The project starts with static templates:

```text
template/
├── index.html
├── style.css
└── script.js
```

The templates are converted into C header files using `xxd`:

```text
index.html
    ↓
xxd
    ↓
index_html.h
```

The generated header contains the file as a C byte array:

```c
unsigned char templates_index_html[] = {
    0x3c, 0x21, 0x44, ...
};
```

When `maker` is compiled, these template bytes become part of the executable itself.

At runtime, the program creates the requested directory, enters it using `chdir()`, and writes the embedded templates using `fwrite()`.

```text
./maker panel
      ↓
mkdir("panel")
      ↓
chdir("panel")
      ↓
create index.html
create style.css
create script.js
```

### Usage

Compile the program:

```bash
gcc maker.c -o maker
```

Run the program with a project name:

```bash
./maker panel
```

The generated project will look like:

```text
panel/
├── index.html
├── style.css
└── script.js
```

The compiled `maker` executable can then be moved somewhere else and used independently because the templates are already embedded into the binary.

For example:

```bash
./maker navbar
```

```text
navbar/
├── index.html
├── style.css
└── script.js
```

### Future Updates

Possible improvements for future versions:

<ul>
    <li>Create a dedicated C tool to automatically convert template files into embedded header files</li>
    <li>Automatically detect and embed new template files</li>
    <li>Add multiple project templates, such as <code>navbar</code>, <code>modal</code>, <code>card</code>, and <code>form</code></li>
    <li>Add command-line options for selecting different templates</li>
    <li>Add better error handling for existing directories and file creation failures</li>
    <li>Allow custom project names and template configurations</li>
    <li>Improve the build process so embedding and compilation can be performed with a single command</li>
    <li>Eventually replace the dependency on <code>xxd</code> with a custom C-based embedding tool</li>
</ul>
