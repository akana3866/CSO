/*
This code was coded solely by Aditi Kanaujia
this file represents the reversed engineered 
code of the foo assembly language
*/
long foo(long d, long e) {
    long a, b, c;
    
    a = (d + d * 2); // leaq (%rdi,%rdi,2), %rax
    a = (d + a * 4); // leaq (%rdi,%rax,4), %rax
    a = a << 2;        // shlq $2, %rax
    
    b = (e + e * 2); // leaq (%rsi,%rsi,2), %rcx
    c = b;             // movq %rcx, %rdx
    c = c << 5;        // shlq $5, %rdx
    
    c = c - b;       // subq %rcx, %rdx
    a = a + c;       // addq %rdx, %rax
    
    e = e - d;       // subq %rdi, %rsi
    c = (e + e * 2); // leaq (%rsi,%rsi,2), %rdx
    c = c << 5;        // shlq $5, %rdx
    
    c = c - e;       // subq %rsi, %rdx
    a = a + c;       //addq %rdx, %rax

    return a;
}