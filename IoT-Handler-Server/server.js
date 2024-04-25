const http = require('http');
const readline = require('readline');
const commands = require('./commands');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', (input) => {
  console.log(useInput(input.toString().split('/')));
});

let Commands = new commands();

useInput = function (args)
{
  let printStr = "";
  let commandType = args[0];

  let command = Commands.commands[commandType]
  args.shift();
  if(command === undefined) printStr = `ERROR: False command tag: ${commandType}`;
  else if(typeof command === 'function') printStr = command(args);

  if(printStr === undefined) return "";
  return printStr;
}

const requestListener = function (req, res) 
{
  res.writeHead(200);
  printStr = useInput(req.url.substring(1).split('/'));
  res.end(printStr);
}

const server = http.createServer(requestListener);
server.listen(8080);
console.log("Server running...");