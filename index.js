console.log("CHECK");
let a = "Shivam";
let b = "Shivam Loves Tanishka"

function reverseString(str){
    let a = str.split(' ');
    a.reverse();
    console.log("converted the string to array");
    console.log(a);
    // a.reverse(); as per wish
    // remember ki .split se string koa rray mn convert kra jaata h kyuki JS mn string immutable hoti h
    let res = a.map(ele => {
        return ele.split('').reverse(' ').join('');
    })
    let res2 = a.filter(ele => {
        return ele==="Shivam";
    })
    console.log(res2);
    console.log(res.join(' '));
}

function checkPalindrome(a){
    let i = 0;
    let j = a.length - 1;

    while(i <= j){
        if(a[i] != a[j]){
            console.log(a, " is not a palindrome");
            return;
        }
        i++;
        j--;
    }

    console.log(a, " is a palindrome");
}

checkPalindrome(a)

if(a === "Shivam"){
    console.log(typeof(a));
    console.log("Same");
}

if({} == {}){
    console.log("same1");
}

if(null == undefined){
    console.log("same2");
}

if([] == []){
    console.log("same3");
}

reverseString(b)

let obj1 = {};
let obj2 = {};

const foo = () => {};
const bar = () => {};

let arr1 = [100, 200, 300]
let arr2 = [100, 200, 300]

console.log(obj1 == obj2);
console.log(foo == bar);
console.log(arr1 == arr2);

let x1 = JSON.stringify(arr1);
console.log(typeof(x1));
console.log(x1);
console.log(JSON.stringify(arr1) == JSON.stringify(arr2));
let x2 = JSON.parse(x1);
console.log(x2);




