import React from "react";
import "./AllCampaignsCardsStyle.css";
import { SingleCampaignCard } from "./SingleCampaignCard";

export function AllCampaignsCards() {
  return (
    <div className="card-deck">
      <SingleCampaignCard />
    </div>
  );
}
