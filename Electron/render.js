const textInput = document.getElementById('calculator-input');

//#region additional operations
const openParentheses = document.getElementById('open-parentheses');
const closeParentheses = document.getElementById('close-parentheses');
const exponent = document.getElementById('exponent');
const backspace = document.getElementById('delete');
//#endregion

//#region Numerals
const num1 = document.getElementById('num1');
const num2 = document.getElementById('num2');
const num3 = document.getElementById('num3');
const num4 = document.getElementById('num4');
const num5 = document.getElementById('num5');
const num6 = document.getElementById('num6');
const num7 = document.getElementById('num7');
const num8 = document.getElementById('num8');
const num9 = document.getElementById('num9');
const num0 = document.getElementById('num0');
const decimal = document.getElementById('decimal');
//#endregion

//#region operators
const add = document.getElementById('add');
const subtract = document.getElementById('subtract');
const multiply = document.getElementById('multiply');
const divide = document.getElementById('divide');
//#endregion

const enter = document.getElementById('enter');

//#region additional operator click events
openParentheses.onclick = () => {
    textInput.value += '(';
}
closeParentheses.onclick = () => {
    textInput.value += ')';
}
exponent.onclick = () => {
    textInput.value += '^';
}
backspace.onclick = () => {
    textInput.value = textInput.value.slice(0, -1);
}
//#endregion

//#region numeric click events
num1.onclick = () => {
    textInput.value += '1';
}
num2.onclick = () => {
    textInput.value += '2';
}
num3.onclick = () => {
    textInput.value += '3';
}
num4.onclick = () => {
    textInput.value += '4';
}
num5.onclick = () => {
    textInput.value += '5';
}
num6.onclick = () => {
    textInput.value += '6';
}
num7.onclick = () => {
    textInput.value += '7';
}
num8.onclick = () => {
    textInput.value += '8';
}
num9.onclick = () => {
    textInput.value += '9';
}
num0.onclick = () => {
    textInput.value += '0';
}
decimal.onclick = () => {
    textInput.value += '.';
}
//#endregion

//#region operator click events
add.onclick = () => {
    textInput.value += '+';
}
subtract.onclick = () => {
    textInput.value += '-';
}
multiply.onclick = () => {
    textInput.value += '*';
}
divide.onclick = () => {
    textInput.value += '/';
}
//#endregion

enter.onclick = () => {
    console.log("SUBMITTED (BUTTON)");
    textInput.value = Module.calculate(textInput.value);
}

function handleForm(event) {
    event.preventDefault();
}

textInput.addEventListener('submit', handleForm);