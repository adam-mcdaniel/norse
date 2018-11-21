import parser
import tables
import strutils
import datatype

type VirtualMachine* = ref object
    program*: string
    data*: seq[Type]
    registers*: Table[string, Type]

proc NewVirtualMachine*(program: string): VirtualMachine = 
    new result
    result.program = program
    result.data = @[]
    result.registers = initTable[string, Type]()
    result.registers["result"] = NewType()

proc NewVirtualMachine*(program: string, vm: VirtualMachine): VirtualMachine = 
    new result
    result.program = program
    result.data = vm.data
    result.registers = vm.registers

method pop*(this: VirtualMachine): Type = this.data.pop()
method push*(this: VirtualMachine, data: Type) = 
    if data.data != @[]:
        this.data.add(data)

method print*(this: VirtualMachine) = 
    let data = this.pop()
    data.print()

method input*(this: VirtualMachine) = 
    var data = NewType()
    data.set(input())
    this.push(data)

method store*(this: VirtualMachine) = 
    var name = this.pop().name()
    var value = this.pop()
    this.registers[name] = value

method load*(this: VirtualMachine) = 
    var name = this.pop().name()
    this.push(this.registers[name])

method str*(this: VirtualMachine) = 
    var operand = this.pop()
    var data = NewType()
    data.set(operand.name())
    this.push(data)

method character*(this: VirtualMachine) = 
    var operand = this.pop()
    var data = NewType()
    data.set(float(operand.character()))
    this.push(data)

method add*(this: VirtualMachine) = 
    var operand1 = this.pop()
    var operand2 = this.pop()
    this.push(operand1.add(operand2))

method subtract*(this: VirtualMachine) = 
    var operand1 = this.pop()
    var operand2 = this.pop()
    this.push(operand1.subtract(operand2))

method multiply*(this: VirtualMachine) = 
    var operand1 = this.pop()
    var operand2 = this.pop()
    this.push(operand1.multiply(operand2))

method divide*(this: VirtualMachine) = 
    var operand1 = this.pop()
    var operand2 = this.pop()
    this.push(operand1.divide(operand2))

method setMember*(this: VirtualMachine) = 
    var obj_name = this.pop()
    var member_name = this.pop()
    var value = this.pop()
    
    # get the value of the object with the name obj_name
    this.push(obj_name)
    this.load()
    var obj = this.pop()
    obj.setMember(member_name.data, value)
    
    # store the value of the object with the name obj_name back into obj_name
    this.push(obj)
    this.push(obj_name)
    this.store()

method getMember*(this: VirtualMachine) = 
    var obj_name = this.pop()
    var member_name = this.pop()
    
    # get the value of the object with the name obj_name and push it
    this.push(obj_name)
    this.load()
    var obj = this.pop()
    this.push(obj.getMember(member_name.data))

method run*(this: VirtualMachine)

method call*(this: VirtualMachine) = 
    let program = this.pop().str()
    var subroutine = NewVirtualMachine(" " & program & " ", this)
    subroutine.run()
    this.data = subroutine.data

method forloop*(this: VirtualMachine) = 
    let n = this.pop()
    let function = this.pop()
    var data = NewType()
    if n.data_type == Float:
        for i in countup(0, int(n.data[0])):
            data.set(float(i))
            this.push(data)
            this.push(function)
            this.call()
    else: discard

method whileloop*(this: VirtualMachine) = 
    let condition = this.pop()
    let function = this.pop()
    
    let program = condition.str()
    var subroutine: VirtualMachine


    
    while true:
        subroutine = NewVirtualMachine(" " & program & " ", this)
        subroutine.run()
        
        for key in subroutine.registers.keys:
            this.registers[key] = subroutine.registers[key]
    
        var return_value = NewType()
        if len(subroutine.data) > 0:
            return_value = subroutine.pop()

        if int(return_value.data[0]) != int(0):
            subroutine = NewVirtualMachine(" " & function.str() & " ", this)
            subroutine.run()
            
            for key in subroutine.registers.keys:
                this.registers[key] = subroutine.registers[key]

            this.data = subroutine.data
        else:
            break


method run*(this: VirtualMachine) = 
    var tokens = Tokenize(this.program)
    var newtokens: seq[Token] = @[]
    for token in tokens:
        if not (token.token_type == Identifier and token.name == ""):
            newtokens.add(token)
            
    tokens = newtokens

    # echo("====Stack Check====")
    # for item in this.data:
    #     echo("(" & item.name & ")")
    # echo("====Token Check====")
    # for token in tokens:
    #     echo("(" & token.name & ")" & " " & $ token.token_type)   
    # echo("====Execute Program====")
    
    for token in tokens:
        case token.token_type
        of Identifier:
            var newtype = NewType()
            newtype.set(token.name)
            this.push(newtype)

        of Literal:
            if token.name[0] in ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']:
                var newtype = NewType()
                newtype.set(parseFloat(token.name))
                this.push(newtype)

            else:
                var newtype = NewType()
                newtype.set(token.name)
                this.push(newtype)

        of Function:
            var newtype = NewType()
            newtype.set(token.name)
            this.push(newtype)

        of Operator:
            case token.name
            of "@": discard this.pop()
            of "?": this.whileloop()
            of ",": this.setMember()
            of ".": this.getMember()
            of "~": this.character()
            of "=": this.store()
            of "$": this.load()
            of "|": this.print()
            of "!": this.call()
            of "&": this.str()
            of "+": this.add()
            of "-": this.subtract()
            of "*": this.multiply()
            of "/": this.divide()
            of "^": this.forloop()
            of "%": this.input()
            else: discard

        else: discard
    # echo("====End Stack Check====")
    # for item in this.data:
    #     echo("(" & item.name & ")") 
    # echo("====End Program====")
    