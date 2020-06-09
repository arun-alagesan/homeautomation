/* eslint-disable */

let webpack = require('webpack');

const version = require("./package.json").version || 0;
process.env.VUE_APP_VERSION = version;

module.exports = {
    publicPath: process.env.NODE_ENV === 'production-mac'
      ? '/iot/my-home/'
      : process.env.NODE_ENV === 'production' ? '/my-home-vue-ui/' : '/',

    configureWebpack :{
      plugins:[
        new webpack.DefinePlugin({
          'process.env' : {
            PACKAGE_VERSION : '"' + version + '"'
          }
        })
      ]
    }

    /* publicPath: process.env.NODE_ENV === 'production'
      ? '/iot/my-home/'
      : '/' */
  }