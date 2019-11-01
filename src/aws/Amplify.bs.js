

import * as Caml_array from "bs-platform/lib/es6/caml_array.js";
import * as AwsAmplify from "aws-amplify";
import * as AwsExports from "../aws-exports";

var env = AwsExports.default;

function dictEntries(dict) {
  var keys = Object.keys(dict);
  var l = keys.length;
  var values = Caml_array.caml_make_vect(l, 0);
  for(var i = 0 ,i_finish = l - 1 | 0; i <= i_finish; ++i){
    var key = keys[i];
    Caml_array.caml_array_set(values, i, /* tuple */[
          key,
          dict[key]
        ]);
  }
  return values;
}

var values = dictEntries(env);

var region = Caml_array.caml_array_get(Caml_array.caml_array_get(values, 0), 1);

var identityPoolId = Caml_array.caml_array_get(Caml_array.caml_array_get(values, 1), 1);

var userPoolId = Caml_array.caml_array_get(Caml_array.caml_array_get(values, 3), 1);

var userPoolWebClientId = Caml_array.caml_array_get(Caml_array.caml_array_get(values, 4), 1);

var config = {
  identityPoolId: identityPoolId,
  region: region,
  userPoolId: userPoolId,
  userPoolWebClientId: userPoolWebClientId
};

var awsConfig = {
  Auth: config
};

var Config = {
  env: env,
  dictEntries: dictEntries,
  values: values,
  region: region,
  identityPoolId: identityPoolId,
  userPoolId: userPoolId,
  userPoolWebClientId: userPoolWebClientId,
  config: config,
  awsConfig: awsConfig
};

function configure(config) {
  AwsAmplify.default.configure(config);
  return /* () */0;
}

var logger = new AwsAmplify.Logger();

function info$1(param) {
  return info.onHubCapsule;
}

var Logger = {
  logger: logger,
  info: info$1
};

export {
  Config ,
  configure ,
  Logger ,
  
}
/* env Not a pure module */