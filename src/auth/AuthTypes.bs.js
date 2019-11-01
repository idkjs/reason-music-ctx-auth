


function fromJsAttrs(attributes) {
  return /* record */[
          /* sub */attributes.sub,
          /* email_verified */attributes.email_verified,
          /* email */attributes.email,
          /* phone_number */attributes.phone_number
        ];
}

function fromJs(data) {
  return /* record */[
          /* username */data.username,
          /* attributes */fromJsAttrs(data.attributes)
        ];
}

export {
  fromJsAttrs ,
  fromJs ,
  
}
/* No side effect */
