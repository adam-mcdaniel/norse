import tables
import sequtils

type DataTypes* = enum
    String, Float, Class, None

type Type* = ref object
    data*: seq[float]
    data_type*: DataTypes
    map: Table[seq[float], Type]

proc NewType*(): Type =
    new result
    result.data = @[]
    result.data_type = None
    result.map = initTable[seq[float], Type]()

method set*(this: Type, data: string) = 
    this.data = @[]
    for c in data:
        this.data.add(float(c))
    this.data_type = String

method set*(this: Type, data: float) = 
    this.data = @[data]
    this.data_type = Float
    
method set*(this: Type, data: Type) = 
    this.data = data.data
    this.data_type = data.data_type

    
    
method setMember*(this: Type, name:seq[float], data: string) = 
    var instance = NewType()
    instance.set(data)
    this.map[name] = instance
    this.data_type = Class
        
method setMember*(this: Type, name:seq[float], data: float) = 
    var instance = NewType()
    instance.set(data)
    this.map[name] = instance
    this.data_type = Class
    
method setMember*(this: Type, name:seq[float], data: Type) = 
    this.map[name] = data
    this.data_type = Class
    
method getMember*(this: Type, name:seq[float]): Type = this.map[name]


method name*(this: Type): string = 
    result = ""
    for c in this.data:
        result &= ($ c)

    
method add*(this: Type, data: Type): Type = 
    assert(this.data_type == data.data_type)
    result = NewType()
    case this.data_type
    of Float:
        result.set(this.data[0] + data.data[0])
    of String:
        result.data = concat(this.data, data.data)
        result.data_type = String
    else: discard
    
method subtract*(this: Type, data: Type): Type = 
    assert(this.data_type == data.data_type)
    result = NewType()
    case this.data_type
    of Float:
        result.set(this.data[0] - data.data[0])
    else: discard
    
method multiply*(this: Type, data: Type): Type = 
    assert(this.data_type == data.data_type)
    result = NewType()
    case this.data_type
    of Float:
        result.set(this.data[0] * data.data[0])
    else: discard
    
method divide*(this: Type, data: Type): Type = 
    assert(this.data_type == data.data_type)
    result = NewType()
    case this.data_type
    of Float:
        result.set(this.data[0] / data.data[0])
    else: discard


method str*(this: Type): string =
    result = ""
    for c in this.data:
        result &= char(int(c))

method character*(this: Type): char = char(int(this.data[0]))

method print*(this: Type) = 
    case this.data_type
    of String:
        for c in this.data:
            stdout.write(char(int(c)))
            
    of Float:
        stdout.write($ this.data[0])
    else: discard

proc input*(): string =
    let s = readLine(stdin)
    case s
    of "": return " "
    else: return s
    