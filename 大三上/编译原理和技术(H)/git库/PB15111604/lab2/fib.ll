define i32 @fib(i32){
	;<label>:1
	%2 = alloca i32, align 4
	%3 = icmp eq i32 %0, 0
	br i1 %3, label %4, label %5

	;<label>:4
	store i32 0, i32* %2, align 4
	br label %14

	;<label>:5
	%6 = icmp eq i32 %0, 1
	br i1 %6, label %7, label %8

	;<label>:7
	store i32 1, i32* %2, align 4
	br label %14

	;<label>:8
	%9 = sub nsw i32 %0, 1
	%10 = call i32 @fib(i32 %9)
	%11 = sub nsw i32 %0, 2
	%12 = call i32 @fib(i32 %11)
	%13 = add nsw i32 %10, %12
	store i32 %13, i32* %2, align 4
	br label %14

	;<label>:14
	%15 = load i32, i32* %2, align 4
	ret i32 %15
}

define i32 @main(){
	;<label>:0
	%1 = alloca i32, align 4 ;ret
	%2 = alloca i32, align 4 ;x
	store i32 0, i32* %2, align 4
	%3 = alloca i32, align 4 ;i
	store i32 0, i32* %3, align 4
	br label %4

	;<label>:4
	%5 = load i32, i32* %3, align 4
	%6 = icmp slt i32 %5, 10
	br i1 %6, label %7, label %15

	;<label>:7
	%8 = load i32, i32* %2, align 4
	%9 = load i32, i32* %3, align 4
	%10 = call i32 @fib(i32 %9)
	%11 = add nsw i32 %8, %10
	store i32 %11, i32* %2, align 4
	br label %12

	;<label>:12
	%13 = load i32, i32* %3, align 4
	%14 = add nsw i32 %13, 1
	store i32 %14, i32* %3, align 4
	br label %4

	;<label>:15
	%16 = load i32, i32* %2, align 4
	ret i32 %16	
}

