# norse
A small DSL I wrote to teach myself Nim. It supports OOP &amp; FP, and it's Turing complete.

## Installation and Usage
```bash
curl https://nim-lang.org/choosenim/init.sh -sSf | sh

git clone "https://github.com/adam-mcdaniel/norse"
cd norse/src
nim c compiler.nim
nim c interpreter.nim

./interpreter ../examples/demo.n
```

All the different commands are explained and demonstrated in the examples.