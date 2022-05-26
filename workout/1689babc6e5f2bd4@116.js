function _1(md){return(
md`# workout
`
)}

function _workout(FileAttachment){return(
FileAttachment("athletes.csv").csv({typed:true})
)}

function _3(Inputs,workout){return(
Inputs.table(workout)
)}

function _4(Plot,workout){return(
Plot.plot({
  marks:[
    Plot.dot(workout, {x: "nationality", y: "height", stroke: "sex"})
  ]
})
)}

function _alpha(FileAttachment){return(
FileAttachment("alpha.csv").csv({typed:true})
)}

function _6(Inputs,alpha){return(
Inputs.table(alpha)
)}

function _7(Plot,alpha){return(
Plot.plot({
  marks: [
    Plot.dot(alpha, {x: "workouttype_code", y: "L_avr_force", stroke: "workouttype_code"})
  ]
})
)}

function _date(Inputs,alpha){return(
Inputs.select(alpha.map(d => d.workout_datetime))
)}

function _selectedDate(alpha,date){return(
alpha.filter(d=> d.workout_datetime === date)
)}

export default function define(runtime, observer) {
  const main = runtime.module();
  function toString() { return this.url; }
  const fileAttachments = new Map([
    ["athletes.csv", {url: new URL("./files/31ca24545a0603dce099d10ee89ee5ae72d29fa55e8fc7c9ffb5ded87ac83060d80f1d9e21f4ae8eb04c1e8940b7287d179fe8060d887fb1f055f430e210007c", import.meta.url), mimeType: "text/csv", toString}],
    ["alpha.csv", {url: new URL("./files/3555a775ca19c50586abb2e933fce1bf2d8aa442ea0c3366ad14651698c8baca7c9b5ff9ba4a5e5bd05f17d335e22704151889aa724ad5fabea665c9e0decad7", import.meta.url), mimeType: "text/csv", toString}]
  ]);
  main.builtin("FileAttachment", runtime.fileAttachments(name => fileAttachments.get(name)));
  main.variable(observer()).define(["md"], _1);
  main.variable(observer("workout")).define("workout", ["FileAttachment"], _workout);
  main.variable(observer()).define(["Inputs","workout"], _3);
  main.variable(observer()).define(["Plot","workout"], _4);
  main.variable(observer("alpha")).define("alpha", ["FileAttachment"], _alpha);
  main.variable(observer()).define(["Inputs","alpha"], _6);
  main.variable(observer()).define(["Plot","alpha"], _7);
  main.variable(observer("viewof date")).define("viewof date", ["Inputs","alpha"], _date);
  main.variable(observer("date")).define("date", ["Generators", "viewof date"], (G, _) => G.input(_));
  main.variable(observer("selectedDate")).define("selectedDate", ["alpha","date"], _selectedDate);
  return main;
}
