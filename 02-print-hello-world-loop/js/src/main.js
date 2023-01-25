#!/usr/bin/env node

const program = require('commander');

program
.description('Command Line Interface Hello World')
.usage('[-h] [-v] [-l LINES]')
.option('-l, --lines <int>', 'Repeat execution "Hello World" times.', 100, parseInt)
.version('Hello World Loop 1.0.0', '-v, --version')
.parse(process.argv);

const options = program.opts();

/***************************************************************************
 *      Main Program
 ***************************************************************************/
function main() {
    if (options == undefined || !options.lines == undefined) {
        console.log(`Error parsing options`);
        return 0;
    }

    const st = new Date();

    for (let i = 0; i < options.lines; i++) {
        console.log(`Hello World`);
    }

    const et = new Date();
    const tt = (et.getTime() - st.getTime()) / 1000;

    console.log(`Time taken to execute ${options.lines} prints: ${tt}`);
}

main();
