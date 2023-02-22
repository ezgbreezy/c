# C Practice: Constants

## Lessons

### Assigning to a cast (constants/cast.c)
You cannot assign a value to a casted variable. Returns error:

```
error: assignment to cast is illegal, lvalue casts are not supported
    (char) c = 'm';
    ^~~~~~~~ ~
```

### Assigning to a dereferenced pointer to a const (constants/point.c)
You cannot reassign a constant using a pointer to a const. Returns error:

```
error: read-only variable is not assignable
    *p = upper;
    ~~ ^
```

