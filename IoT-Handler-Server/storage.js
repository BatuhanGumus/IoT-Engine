var storage = function() {
    this.data = {
        "rgbLight": {"red": 0, "green": 0, "blue": 255},
        "stepperMotor": {"direction": 1},
    };
    this.functions = {
        "testFunction": testFunction,
    };
};
  
function testFunction()
{
    console.log("test function called");
}

module.exports = storage;