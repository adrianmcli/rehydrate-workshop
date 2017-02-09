# Rehydrate Workshop

A short demo of basic things you can do with Rehydrate.

# Installation

Requires the [Ninja](https://ninja-build.org/) build tool.

```bash
# 1. Make sure that the Ninja build tool is installed:
brew install ninja

# 2. Clone the repo and install project dependencies (this can take a while).
npm install

# 3. Launch the watcher that compiles Reason files to JS.
npm start

# 4. In another tab, run a Webpack watcher to prep the JS files to be run in the browser.
npm run build
```

Finally, inside the `output` folder, open the HTML file of your choice.
