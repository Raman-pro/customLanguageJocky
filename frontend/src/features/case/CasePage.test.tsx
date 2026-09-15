import { render, screen } from "@testing-library/react";
import userEvent from "@testing-library/user-event";
import { MemoryRouter } from "react-router-dom";
import { afterEach, expect, it, vi } from "vitest";
import { DemoProvider } from "../../app/DemoProvider";
import { CasePage } from "./CasePage";

afterEach(() => vi.useRealTimers());

function renderCase() {
  return render(
    <MemoryRouter>
      <DemoProvider>
        <CasePage />
      </DemoProvider>
    </MemoryRouter>,
  );
}

it("reviews scope and completes the deterministic collection", async () => {
  vi.useFakeTimers({ shouldAdvanceTime: true });
  const user = userEvent.setup({ advanceTimers: vi.advanceTimersByTime });
  renderCase();

  await user.click(await screen.findByRole("button", { name: "Start collection" }));
  expect(screen.getByRole("dialog", { name: "Review collection" })).toBeVisible();
  expect(screen.getByText("Network + process triage")).toBeVisible();
  expect(screen.getByText("3 selected hosts")).toBeVisible();
  await user.click(screen.getByRole("button", { name: "Run collection" }));
  await vi.advanceTimersByTimeAsync(6500);

  expect(screen.getByText("24 evidence records received")).toBeVisible();
  expect(screen.getByRole("link", { name: "Explore evidence" })).toBeVisible();
});
