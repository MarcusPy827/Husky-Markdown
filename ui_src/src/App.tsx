import React, { useEffect } from 'react';
import { setColorScheme } from 'mdui';
import './App.css';

const App: React.FC = () => {
    useEffect(() => {
        setColorScheme('#88C0D0');
    }, []);

    return(
        <>
            A
        </>
    );
}

export default App;