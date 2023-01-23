const argv = require('minimist')(process.argv.slice(2));
const name = argv._[0];
const lines = argv.lines || 100;

if(!name) {
    console.error("Error: No parameter name");
    process.exit(1);
}

const st = new Date();

for (let i = 0; i < lines; i++) {
    console.log(`Hello ${name}`);
}

const et = new Date();
const tt = (et.getTime() - st.getTime()) / 1000;

console.log(`Time taken to execute ${lines} prints: ${tt}`);
