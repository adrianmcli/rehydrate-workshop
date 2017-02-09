const path = require('path');

module.exports = {
  entry: {
    simple: './lib/js/src/simple.js',
  },
  output: {
    path: path.join(__dirname, "output"),
    filename: '[name].js',
  },
};
