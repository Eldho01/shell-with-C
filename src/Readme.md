## Usage

Use *CMakeLists.txt* on the root folder to build the project.

```bash
cd ..
mkdir -p build && cd build
cmake ..
cmake --build .
```

The executable will be placed at runtime in root_folder/build/out 

## Features

Current project run basic coreutils provided by GNU(ls, echo, cat etc.)
Bulitins added for cd and pwd commnads

## TODO

This project can be imporved further by adding more builtins (history, kill, alias etc.)
Also allowing Pipelinig commands, multiline commands etc.

