open ReactUtils; // (A)

[@react.component]
let make = () =>
  <div className="section is-fullheignt">
    <div className="container">
      <div className="column is-6 is-offset-4">
        <h1 className="is-size-2 has-text-centered">
           {s("Reason Music Player")} </h1> // (A)
        <br />
      </div>
    </div>
  </div>;

