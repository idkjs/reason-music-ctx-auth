


function userResponsefromJs(data) {
  return /* record */[
          /* username */data.username,
          /* pool */data.pool,
          /* session */data.Session,
          /* client */data.client,
          /* signInUserSession */data.signInUserSession,
          /* storage */data.storage,
          /* keyPrefix */data.keyPrefix,
          /* userDataKey */data.userDataKey,
          /* attributes */data.attributes,
          /* preferredMFA */data.preferredMFA
        ];
}

export {
  userResponsefromJs ,
  
}
/* No side effect */
