module.exports = {
  // ...other configurations
  resolve: {
    fallback: {
      fs: false, // or you can install a browser-based version if needed
      child_process: false,
      path: require.resolve('path-browserify'),
      util: require.resolve('util/'),
      stream: require.resolve('stream-browserify'),
      os: require.resolve('os-browserify/browser')
    },
  },
};
