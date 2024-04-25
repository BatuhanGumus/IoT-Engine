const storage = require('./storage');

var commands = function()
{
    this.commands = {
        "GET": GET,
        "SET": SET,
        "PUT": PUT,
        "DELETE": DELETE,
    };

    let Storage = new storage();

    function GET(args)
    {
        let data = Storage.data[args[0]];
        if(data === undefined) return `ERROR: False name tag: ${args[0]}`;

        return JSON.stringify(data);
    }

    function SET(args)
    {
        Storage.data[args[0]] = JSON.parse(args[1]);
        printStr = `set value of ${args[0]} to: ${args[1]}`;
        return printStr;
    }

    function PUT(args)
    {

    }

    function DELETE (args)
    {
        delete Storage.data[args[0]];
        printStr = `Deleted ${args[0]} from data`;
    }
}

module.exports = commands;


/*
function GET(args)
    {
        let data = Storage.data[args[0]];
        if(data === undefined) return `ERROR: False name tag: ${args[0]}`;

        while(args.length > 1)
        {
            data = data[args[1]];
            if(data === undefined) return `ERROR: False name tag: ${args[1]}`;
            args.shift();
        }

        return JSON.stringify(data);
    }
*/