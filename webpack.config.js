const path = require('path');

module.exports = {
  entry: {
    simple: './lib/js/src/simple.js',
    counter: './lib/js/src/counter.js',
    input: './lib/js/src/input.js',
    input2: './lib/js/src/input2.js',
  },
  output: {
    path: path.join(__dirname, "output"),
    filename: '[name].js',
  },
};
