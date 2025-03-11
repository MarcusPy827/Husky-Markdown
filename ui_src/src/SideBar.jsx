import './Colors.css'
import './SideBar.css'
import { useState } from 'react'
import folderIcon from './assets/folder.svg'
import folderIconActive from './assets/folder_active.svg'
import tableOfContent from './assets/table_of_content.svg'
import tableOfContentActive from './assets/table_of_content_active.svg'
import versionControl from './assets/version_control.svg'
import versionControlActive from './assets/version_control_active.svg'

let currentToolTitle = 'File Manager';

export default function SideBar() {
    return(
        <>
            <div className='sidebar-container'>
                <div className='sidebar-icon-row'>
                    <SideBarIconBtn iconDefaultSrc={folderIcon} iconActiveSrc={folderIconActive} defaultActive={true}/>
                    <SideBarIconBtn iconDefaultSrc={tableOfContent} iconActiveSrc={tableOfContentActive}/>
                    <SideBarIconBtn iconDefaultSrc={versionControl} iconActiveSrc={versionControlActive}/>
                </div>

                <div className='sidebar-tool-widget'>
                    <span className='sidebar-tool-title'>{currentToolTitle}</span>
                    <SideBarWidget />
                </div>

                <div className='sidebar-divider'></div>
            </div>
        </>
    );
}

export function SideBarIconBtn({iconDefaultSrc, iconActiveSrc, defaultActive = false}) {
    const [isActive, setIsActive] = useState(defaultActive);

    return(
        <>
            <div
                className={`sidebar-icon-btn ${isActive ? "sidebar-icon-btn-active" : ""}`}
                onClick={() => setIsActive(!isActive)}>
                <img className='sidebar-icon' src={ isActive ? iconActiveSrc : iconDefaultSrc } alt="open_folder" />
            </div>
        </>
    );
}

export function FileManager() {
    return(
        <>
            currently work in progress
        </>
    );
}

export function SideBarWidget() {
    if(currentToolTitle === 'File Manager'){
        return <FileManager />
    }
}