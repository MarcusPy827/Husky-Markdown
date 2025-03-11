import { StrictMode } from 'react'
import { createRoot } from 'react-dom/client'
import './index.css'
import Interface from './Interface.jsx'

createRoot(document.getElementById('root')).render(
  <StrictMode>
    <Interface />
  </StrictMode>,
)
