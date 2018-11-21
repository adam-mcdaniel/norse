import os
import osproc
import streams
import strutils

import norse.parser
import norse.datatype
import norse.virtualmachine


proc removeComments*(line: string, sep: char): string =
    line.split(sep)[0].strip(leading = false)


proc getProgram*(filename: string): string = 
    var line = ""
    var program = ""
    var file = newFileStream(filename, fmRead)

    if not isNil(file):
        while file.readLine(line):
            line = removeComments(line, '#')
            program &= line & "\n"
        file.close()
    
    result = program


var program = getProgram(paramStr(1))

var output = newFileStream("./output.nim", fmWrite)

output.write("""
import os
import streams
import strutils

import norse.parser
import norse.datatype
import norse.virtualmachine


proc removeComments*(line: string, sep: char): string =
    line.split(sep)[0].strip(leading = false)


proc getProgram*(filename: string): string = 
    var line = ""
    var program = ""
    var file = newFileStream(filename, fmRead)

    if not isNil(file):
        while file.readLine(line):
            line = removeComments(line, '#')
            program &= line & "\n"
        file.close()
    
    result = program


var program = """ & "\"\"\"" & program & "\"\"\"" & """

var vm = NewVirtualMachine(" " & join(split(program), " ") & " ")
vm.run()
""")

output.close()

discard execCmd("nim c output.nim")
discard execCmd("rm output.nim")
