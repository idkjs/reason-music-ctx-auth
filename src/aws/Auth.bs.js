

import * as AwsAmplify from "aws-amplify";

var currentAuthenticatedUser = AwsAmplify.Auth.currentAuthenticatedUser().then((function (res) {
        return Promise.resolve(res);
      }));

function signIn(username, password) {
  return AwsAmplify.Auth.signIn(username, password).then((function (res) {
                return Promise.resolve(res);
              }));
}

function signUp(username, password, attributes) {
  return AwsAmplify.Auth.signUp(username, password, attributes).then((function (res) {
                return Promise.resolve(res);
              }));
}

function confirmSignUp(username, confirmationCode) {
  return AwsAmplify.Auth.confirmSignUp(username, confirmationCode).then((function (res) {
                return Promise.resolve(res);
              }));
}

function forgotPassword(username) {
  return AwsAmplify.Auth.forgotPassword(username).then((function (res) {
                return Promise.resolve(res);
              }));
}

function forgotPasswordSubmit(username, confirmationCode, password) {
  return AwsAmplify.Auth.forgotPasswordSubmit(username, confirmationCode, password).then((function (res) {
                return Promise.resolve(res);
              }));
}

function currentUserPoolUser(userPoolId) {
  return AwsAmplify.Auth.currentUserPoolUser(userPoolId).then((function (res) {
                return Promise.resolve(res);
              }));
}

export {
  currentAuthenticatedUser ,
  signIn ,
  signUp ,
  confirmSignUp ,
  forgotPassword ,
  forgotPasswordSubmit ,
  currentUserPoolUser ,
  
}
/* currentAuthenticatedUser Not a pure module */