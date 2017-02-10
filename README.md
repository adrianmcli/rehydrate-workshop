# Rehydrate Workshop

A small collection of basic components built with Rehydrate.

## Includes

* `simple.re` — A simple example of passing a prop down into a stateless component.
* `counter.re` — An increment/decrement counter that demonstrates use of event handlers.
* `input.re` — A controlled input with a simple demonstration of pattern matching.
* `input2.re` — A text input that sends its contents on Enter key down via a GET request.
* `groupcounter.re` — An increment/decrement counter with long polling, promise handling, and instance variables.

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
