module.exports = {
    publicPath: process.env.NODE_ENV === 'production-mac'
      ? '/iot/my-home/'
      : process.env.NODE_ENV === 'production' ? '/my-home-vue-ui/' : '/'

    /* publicPath: process.env.NODE_ENV === 'production'
      ? '/iot/my-home/'
      : '/' */
  }