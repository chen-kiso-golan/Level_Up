import axios from "axios";

const TwitterAddress = "http://localhost:7205/api/twitter";

export const MakeA_TweetInTwitter = async (Tweet) => {
  try {
    console.log("services - twitter - MakeA_TweetInTwitter ran Successfully");
    await axios.post(`${TwitterAddress}/post-MakeATweet`, Tweet);
  } catch (ex) {
    console.log(`An Exception occurred while initializing the MakeA_TweetInTwitter Service : ${ex}`);
  }
};

export const getAllTweetsToUpdateDB = async () => {
  try {
    console.log("services - twitter - getAllTweetsToUpdateDB ran Successfully");
    let endpoint = await axios.get(`${TwitterAddress}/getAllTweetsToUpdateDB`);
    if (endpoint.status === 200) {
      return endpoint.data;
    } else {
      return null;
    }
  } catch (ex) {
    console.log(`An Exception occurred while initializing the getAllTweetsToUpdateDB Service : ${ex}`);
  }
};

export const getAllTwitsFromDB = async () => {
  try {
    console.log("services - twitter - getAllTwitsFromDB ran Successfully");
    let endpoint = await axios.get(`${TwitterAddress}/getAllTwitsFromDB`);
    return endpoint;
  } catch (ex) {
    console.log(`An Exception occurred while initializing the getAllTwitsFromDB Service : ${ex}`);
  }
};
