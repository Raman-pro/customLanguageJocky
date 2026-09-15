# JOCKY Forensic Command Center

Local presentation frontend using deterministic mock evidence.

## Run

```bash
npm install
npm run dev
```

Open `http://localhost:5173/fleet`. Use **Reset demo** before presenting.

## Verify

```bash
npm run check
npx playwright install chromium
npm run test:e2e
```

The application does not contact endpoints or execute the JOCKY compiler.

## Visual design

The console uses an operational workspace layout: a navy application header,
neutral navigation, white panels, visible table boundaries, and blue actions.
Manrope is used consistently for interface text; JetBrains Mono is reserved for
source, addresses, timestamps, and hashes. Both fonts are bundled locally.

Typography and colour tokens are in `src/styles/tokens.css`. The complete active
layout and component styles are in `src/styles/global.css`. The earlier
`editorial.css` experiment is not loaded by the application.

The layout adapts from a sidebar to horizontal navigation on smaller screens.
Tables become labelled records on phones, and evidence opens in a full-width
inspector. The mock collection, evidence filters, build comparison, export, and
reset flow remain available.
