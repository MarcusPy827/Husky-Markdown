/// <reference types="vite/client" />
/// <reference types="mdui/jsx.zh-cn.d.ts" />
import type * as React from 'react';

declare module 'react' {
    namespace JSX {
        interface IntrinsicElements {
            [elemName: `mdui-icon-${string}`]: React.DetailedHTMLProps<React.HTMLAttributes<HTMLElement>, HTMLElement>;
        }
    }
}