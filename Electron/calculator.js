class Calculator {
    priority = {
        '^':3,
        '*':2,
        '/':2,
        '+':1,
        '-':1,
        '`':0
    };
    operationList;
    valueList;

    constructor() {
        console.log('Calculator created');
    }

    arithmetic(val1, val2, operator) {
        var result = 0.0;

        switch(operator) {
            case '+':
                result = val1 + val2;
                break;

            case '-':
                result = val1 - val2;
                break;

            case '*':
                result = val1 * val2;
                break;
            
            case '/':
                result = val1 / val2;
                break;
    
            case '^':
                result = Math.pow(val1, val2);
                break;
            
            default:
                break;
        }

        return result;
    }

    findParenthesis(input) {
        var subExp;
        var temp;

        for (var i = 0; i < input.length; i++) {
            if (input[i] === '(') {
                subExp = input.substring(i + 1);
                subExp = this.findParenthesis(subExp);
                input = input.substring(0, i) + subExp;
            } else if (input[i] === ')') {
                subExp = input.substring(0, i);
                temp = this.solveExpression(subExp).toString();
                subExp = input.substring(i + 1);
                input = temp + subExp;                
                return input;
            }
        }
        return input;
    }
    
    isDigit(str) {
        if (typeof str != "string") return false;
        return !isNaN(str) && !isNaN(parseFloat(str));
    }

    solveExpression(input) {
        input = this.findParenthesis(input);

        this.valueList = [];
        this.operationList = [];

        var val = 0;
        var decimalPlaces = 1;
        var state = "IN_FRONT";

        for (let i = 0; i < input.length; i++) {
            const currerentChar = input[i];
            if (this.isDigit(currerentChar)) {
                switch (state) {
                    case "IN_FRONT":
                        val = val * 10 + parseInt(currerentChar);
                        break;
                    case "AFTER":
                        val = (val + parseInt(currerentChar)) / (10 * decimalPlaces);
                        decimalPlaces++;
                        break;
                    default:
                        break;
                }
            } else if (currerentChar === ' ') {
                /*Ignore Spaces*/
            } else if (currerentChar === '.') {
                state = "AFTER";
            } else {
                decimalPlaces = 1;
                state = "IN_FRONT";
                this.valueList.push(val);
                this.operationList.push(currerentChar);
                val = 0;
            }
        }
        this.valueList.push(val);

        while (this.operationList.length) {
            for (let i = 0; i < this.operationList.length; i++) {
                var previousOperator;
                var val1, val2;
                
                if ((i - 1) < 0) {
                    previousOperator = '`';
                } else {
                    previousOperator = this.operationList[i - 1];
                }

                if (this.priority[this.operationList[i].toString()] <= this.priority[previousOperator.toString()]) {
                    val1 = this.valueList[i - 1];
                    val2 = this.valueList[i];
                    this.valueList.splice(i);
                    this.valueList[i - 1] = this.arithmetic(val1, val2, previousOperator);
                    this.operationList.splice(i - 1);
                } else if (i === this.operationList.length - 1) {
                    val2 = this.valueList.at(-1);
                    this.valueList.pop();
                    val1 = this.valueList.at(-1);
                    this.valueList.pop();
                    this.valueList.push(this.arithmetic(val1, val2, this.operationList.at(-1)));
                    this.operationList.pop();
                }
            }
        }
        return this.valueList[this.valueList.length - 1];
    }

    expressionWrapper(input) {
        return this.solveExpression(input);
    }
}