## Assignment 5 - Run Times
#### Due: 03-02-2021 (Tuesday @ 12:30 p.m.)


-----

- Count = ______1048576________
  
- Complexity = _______n^2, O(n^2)_______
  
```cpp
int count = 0;
int n = 1024;
for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++){
        count++;
    }
}
cout<<count<<endl;
```

-----

- Count = ______523776_________
  
- Complexity = ____( n^2 - n ) / 2, O(n^2)__________
  
```cpp
int count = 0;
int n = 1024;
for(int i = 0; i < n; i++) {
    for(int j = 0; j < i; j++){
        count++;
    }
}
cout<<count<<endl;
```

-----

- Count = ___536346624________
  
- Complexity = ______(n^3 - n^2) / 2, O(n^3)______
  
```cpp
int count = 0;
int n = 1024;
for(int i = 0; i < n; i++) {
    for(int j = 0; j < i; j++){
        for(int k = 0; k < n; k++){
            count++;
        }
    }
}
cout<<count<<endl;
```

-----

- Count = _______2048______________
  
- Complexity = ___2n, O(n)
  
```cpp
int count=0;
int n = 1024;
for(int i = 0; i < 2*n; i++) {
    count++;
}
cout<<count<<endl;
```

-----

- Count = ______2097152
  
- Complexity = ___n^2 + n^2, O(n^2)
  
```cpp
int count=0;
int n = 1024;
for(int i = 0; i < n; i++) {
    for(int j = 0; j < 2n; j++){
        count++;
    }
}
cout<<count<<endl;
```

-----

- Count = _____________________524800
  
- Complexity = ________________(n^2 + n) / 2, O(n^2)  
```cpp
int count=0;
int n = 1024;
for(int i = 0; i < n; i++) {
    count++;
}
for(int j = 0; j < n; j++){
    for(int k = 0; k < j; k++){
        count++;
    }
}
cout<<count<<endl;
```

-----

- Count = _____________________11264
  
- Complexity = ________________O(n^2)
  
```cpp
int count = 0;
int n = 1024;
int i = n;

while(i>0){
    for(int j = 0; j < n; j++){
        count++;
    }
    i /= 2;
    cout<<i<<endl;
}
cout<<count<<endl;
```

-----

- Comparisons = ______n/2
  
- Complexity = _____O(log n)
  
```cpp
bool found = 0;
int n = 1024;
int i = n;

// assume loaded with random numbers
// and in ascending order.
int *A = new int[n];

// Whats most number of comparisons?
// Whats the complexity?
found = BinarySearch(A,n);

```

-----

- Count = _____________________ 12
  
- Complexity = ________________ O(n)
  
```cpp
int count = 0;
int n = 1024;

int i = n;
while(i>0){
    cout<<i<<endl;
    i /= 2;  
}
cout<<count<<endl;
```

-----
