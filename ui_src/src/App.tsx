import React, { useEffect } from 'react';
import { setColorScheme } from 'mdui';
import 'mdui/mdui.css';
import 'mdui';
import './App.css';
import '@mdui/icons/folder--outlined.js';
import './i18n.ts';
import { useTranslation } from "react-i18next";

const App: React.FC = () => {
    useEffect(() => {
        setColorScheme('#88C0D0');
    }, []);

    const { t } = useTranslation();

    return (
        <>
            <div className="mdui-prose">
                <div className="notebook-type-title">
                    <mdui-icon-folder--outlined></mdui-icon-folder--outlined>
                    <span className="notebook-type-title-padding"><b>{t('Notebooks')}</b></span>
                </div>
                <mdui-divider></mdui-divider>
            </div>
        </>
    );
}

export default App;