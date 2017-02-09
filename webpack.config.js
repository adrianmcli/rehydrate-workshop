const path = require('path');

module.exports = {
  entry: {
    simple: './lib/js/src/simple.js',
    counter: './lib/js/src/counter.js',
  },
  output: {
    path: path.join(__dirname, "output"),
    filename: '[name].js',
  },
};
