#!/Users/arturadamian/.nvm/versions/node/v10.15.3/bin/node

const request = require('request');

request('https://swapi-api.hbtn.io/api/films/' + process.argv[2], function (err, res, body) {
  if (err) throw err;
  const actors = JSON.parse(body).characters;
  exactOrder(actors, 0);
});
const exactOrder = (actors, x) => {
  if (x === actors.length) return;
  request(actors[x], function (err, res, body) {
    if (err) throw err;
    console.log(JSON.parse(body).name);
    exactOrder(actors, x + 1);
  });
};

// const req = (arr, i) => {
//   if (i === arr.length) { return; }
//   request(arr[i], (err, response, body) => {
//     if (err) {
//       console.log(err);
//     } else {
//       console.log(JSON.parse(body).name);
//       req(arr, i + 1);
//     }
//   });
// };

// request(`https://swapi-api.hbtn.io/api/films/${process.argv[2]}`, (err, response, body) => {
//   if (err) {
//     console.log(err);
//   } else {
//     const chars = JSON.parse(body).characters;
//     req(chars, 0);
//   }
// });
