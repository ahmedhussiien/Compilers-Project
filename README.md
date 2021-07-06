# Compilers-Project

## Syntax

### Variables declaration.

```
int x = 5 + 1;
float z = 1.5;
bool isActive = true;
string name = "compiler";
```

### Constants declaration

```
const float x = 3.1415;
```

### Mathematical expressions

```
int x = 1;
print(x + 1);
print(-x * 5);
print(-x * 2 + 5 + (-1*x));
```

### Logical expressions

```
int x = 1;
int y = 3;
print( x < 1 );
print( x < y );
print( x == y );
print( not ( x == y));
print( (1 > 2) and ( 1 > 0));
print( (1 > 2) or ( 1 > 0));
```

### Assignment statement

```
int x = 10;
x = 5 + 2;
x = x + 1;
```

### If-else statement

```
int x = 1;
if(x < 1)
    x = x + 1;
else {
    x = x + 2;
    print(x);
}
```

### While loops

```
int x = 1;
while(x < 4){
    x = x + 1;
    print(x);
}
```

### Do-while loops

```
int x = 1;
do{
    x = x + 1;
    print(x);
} while (x < 1)
```

### for loops

```
for(int y = 1; y < 4; y = y + 1){
    print (y);
    y = y + 1;
}

int x = 1;
for(; x < 4; x = x +1)
    print (x);
```

### switch statement

```
int x = 1;
switch(x){
    case x + 1:
        print(x);
    case x: {
        x = x + 1;
        print(x);
    }
}
```

### Functions

#### Declaration

```
int add(int x, int y){
    return x + y;
}

print(add(1, 2));
```

#### Default argument

```
int add(int x, int y, int z = 0){
    int result = x + y + z;
    print(result);
    return result;
}

add(1, 4);
```

### Comments

```
// Hello!
int x = 1;

/* Multiline
   comments
   are
   supported!
*/
print(x);
```
