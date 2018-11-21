# norse
![Norse](logo.png)
![Norse](name.png)

A small DSL I wrote to teach myself Nim. It supports OOP &amp; FP, and it's Turing complete.

## Example OOP Script

```
[
    <@> this =
    [ this =
        # <calling init> |
        # im a comment

        < > <>> + |
        % i this ,
        this $
    ] init this , 
    
    this $
] obj =

obj $ ! instance =

instance $ init instance . ! instance =


< your mom ;)> i instance . + |

<\n> |
```

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
