// strings, bools, logical ops, user functions
fn starts_with_abc(s: str) : bool {
    return len(s) >= 3 && s == "abc";
}

fn main() {
    print("abc");                  // abc
    print(starts_with_abc("abc")); // true
    print(starts_with_abc("xy"));  // false
    let flag: bool = !false;
    print(flag && true);           // true
    print(flag || false);          // true
    let n: int = 0;
    if (true) {
        let n: int = 100;          // shadowing
        print(n);                  // 100
    }
    print(n);                      // 0
}