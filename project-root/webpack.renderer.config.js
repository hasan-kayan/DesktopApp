const path = require('path');
const HtmlWebpackPlugin = require('html-webpack-plugin');

module.exports = (env, argv) => {
  const isDevelopment = argv.mode === 'development';

  return {
    mode: argv.mode || 'production',  // Automatically set mode based on the script
    target: 'web',
    entry: './src/components/Home/Home.js',
    output: {
      path: path.resolve(__dirname, 'dist'),
      filename: 'renderer.bundle.js'
    },
    devtool: isDevelopment ? 'inline-source-map' : false,  // Use inline source maps in development
    module: {
      rules: [
        {
          test: /\.js$/,
          exclude: /node_modules/,
          use: {
            loader: 'babel-loader',
            options: {
              presets: ['@babel/preset-env', '@babel/preset-react']
            }
          }
        },
        {
          test: /\.css$/,
          use: ['style-loader', 'css-loader']
        }
      ]
    },
    plugins: [
      new HtmlWebpackPlugin({
        template: './public/index.html',
        filename: 'index.html'
      })
    ],
    devServer: {
      contentBase: path.join(__dirname, 'dist'),
      hot: true,  // Enable hot module replacement
      port: 8080,
      host: '0.0.0.0',  // Allows access from local network
      headers: {
        'Content-Security-Policy': "default-src 'self'; script-src 'self' 'unsafe-inline' 'unsafe-eval'; style-src 'self' 'unsafe-inline';"
      }
    }
  };
};
