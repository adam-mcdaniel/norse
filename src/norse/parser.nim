import strutils

type TokenType* = enum
    Function, Literal, Identifier, Operator

type Token* = ref object
    name*: string
    token_type*: TokenType

proc NewToken*(name: string, token_type: TokenType): Token = 
    new result
    result.name = name
    result.token_type = token_type


proc Tokenize*(program: string): seq[Token] = 
    result = @[]
    var isFunction = false
    var isLiteral = false
    var program = replace(program, "\\n", "\n")
    var tokens = program
    var i = 0

    var layer = 0
    var current_token = ""
    var c: char

    var appendToken = true

    while true:
        try:
            c = tokens[i]
        except:
            break

        appendToken = true

        if not isFunction and not isLiteral:
            if c == '<':
                appendToken = false
                isLiteral = true
                
            elif c == '[':
                appendToken = false
                isFunction = true
                
        if isLiteral:
            if c == '>' and tokens[i+1] != '>':
                appendToken = false
                isLiteral = false
                current_token = current_token.substr(1)
                result.add(NewToken(current_token, Literal))
                current_token = ""

        elif isFunction:
            if c == '[':
                layer += 1
            elif c == ']':
                layer -= 1
                if layer == 0:
                    appendToken = false
                    isFunction = false
                    current_token = current_token.substr(1)
                    result.add(NewToken(current_token, Function))
                    current_token = ""
        
        else:
            if c == ' ' and len(current_token) > 0:
                current_token = current_token.substr(1)
                if current_token[0] in ['$', '=', '.', ',', '!', '?', '+', '*', '-', '/', '|', '&', '^', '%', '~', '@']:
                    result.add(NewToken(current_token, Operator))
                else:
                    result.add(NewToken(current_token, Identifier))
                current_token = ""
    
        if appendToken:
            current_token &= $ c

        i += 1