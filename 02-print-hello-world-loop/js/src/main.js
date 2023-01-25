#!/usr/bin/env node

const argv = require('minimist')(process.argv.slice(2));
let lines = argv._[0];

/***************************************************************************
 *      Main Program
 ***************************************************************************/
function main() {
    if (!lines) {
        lines = 100;
    }

    const st = new Date();

    for (let i = 0; i < lines; i++) {
        console.log(`Hello World`);
    }

    const et = new Date();
    const tt = (et.getTime() - st.getTime()) / 1000;

    console.log(`Time taken to execute ${lines} prints: ${tt}`);
}

main();
