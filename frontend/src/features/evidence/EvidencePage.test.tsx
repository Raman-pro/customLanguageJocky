import { render, screen, within } from "@testing-library/react";
import userEvent from "@testing-library/user-event";
import { MemoryRouter } from "react-router-dom";
import { DemoProvider } from "../../app/DemoProvider";
import { EvidencePage } from "./EvidencePage";

function renderEvidence() {
  return render(
    <MemoryRouter initialEntries={["/cases/JKY-104/evidence"]}>
      <DemoProvider>
        <EvidencePage />
      </DemoProvider>
    </MemoryRouter>,
  );
}

it("filters evidence and opens a provenance inspector", async () => {
  const user = userEvent.setup();
  renderEvidence();

  expect(await screen.findByRole("heading", { name: "Evidence explorer" })).toBeVisible();
  await user.click(screen.getByRole("tab", { name: "Network" }));
  await user.type(screen.getByRole("searchbox", { name: "Search evidence" }), "198.51.100.42");
  await user.click(screen.getByRole("button", { name: /powershell.exe connected to 198.51.100.42:443/i }));

  const inspector = screen.getByRole("dialog", { name: "Evidence record" });
  expect(inspector).toBeVisible();
  expect(within(inspector).getByText("Mock evidence for presentation")).toBeVisible();
  expect(within(inspector).getByText("SHA-256")).toBeVisible();
  expect(within(inspector).getByText("net.sockets")).toBeVisible();
});
