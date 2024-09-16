const path = require("path");
const HtmlWebpackPlugin = require("html-webpack-plugin");

module.exports = {
  entry: "./src/components/Home/Home.js", // Starting point of your React app
  output: {
    path: path.resolve(__dirname, "dist"),
    filename: "bundle.js",
  },
  module: {
    rules: [
      {
        test: /\.js$/,
        exclude: /node_modules/,
        use: "babel-loader",
      },
      {
        test: /\.css$/,
        use: ["style-loader", "css-loader"],
      },
    ],
  },
  plugins: [
    new HtmlWebpackPlugin({
      template: "./public/index.html",
    }),
  ],
  resolve: {
    fallback: {
      fs: false, // or you can install a browser-based version if needed
      child_process: false,
      path: require.resolve("path-browserify"),
      util: require.resolve("util/"),
      stream: require.resolve("stream-browserify"),
      os: require.resolve("os-browserify/browser"),
    },
  },
};
